//
//  BulletDark.m
//  BulletDark
//
//  Created by h4ck on 2019/1/17.
//  Copyright (c) 2019年 h4ck. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "BulletDark.h"
#import <CaptainHook/CaptainHook.h>
#import "NTESRedPacketManager.h"
#import "SMViewController.h"
#import "SMUTility.h"
#import "NIMManager-Protocol.h"
#import "NIMManager.h"
#import "NIMChatManager-Protocol.h"
#import "NIMChatManager.h"
#import "NIMChatManagerWrapper.h"
#import "NIMMessage.h"
#import "NIMMessageInfo.h"
#import "SMBaseApiManager.h"
#import "SMC2CRedPacketApiManager.h"
#import "OpenRedPacketRequest.h"
#import "SMSensorsManager.h"
#import "NIMCustomObject.h"
#import "NTESRedPacketAttachment.h"
#import "SMHttpResponse.h"
#import "OpenRequest.h"
#import "SMC2CRedPacketV2ApiManager.h"
#import "NIMSession-SMNIMSession.h"
#import "NIMSession.h"
#import "NIMSessionManager.h"
#import "SMScanResultHandler.h"
#import "LBXScanNative.h"
#import "NIMImageObject.h"
#import "SDWebImageManager.h"
#import "SDImageCache.h"
#import "NIMFileCenter.h"
#import "NIMSDK.h"
#import "NIMTeamManager.h"
#import "NTESLoginManager.h"
#import "NTESSessionViewController.h"
#import "WMDragView.h"
#import "NIMTeam.h"
#import "QHSpeechSynthesizerQueue.h"

static QHSpeechSynthesizerQueue *g_speechSynthesizerQueue;

CHDeclareClass(NIMChatManager)
CHMethod1(void, NIMChatManager, onRecvMessages, NSArray<NIMMessage *> *, messages){
    CHSuper1(NIMChatManager, onRecvMessages, messages);
//    ****** NIMMessage <NIMMessage: 0x280f0c750> Info ******
//    serial        : 13
//    serverId      : 250124413071
//    messageId     : 6f36f215-40c3-4b1b-aadb-f352319aded9
//    messageType   : 100
//    sessionId     : 5075813000
//    sessionType   : 0
//    time          : 1547680190.70
//    text          : (null)
//    messageObject : {"type":15,"data":{"redPacketType":1,"message":"恭喜发财，万事如意","title":"","redPacketStatus":0,"redPacketId":"V6BGD6D5K52T2IXA4QPQZEXCXILYKWT76ZWABJKMO7A5VP3OCGEQ","isCollected":false}}
//    attachmentDownloadState : 3
//    received msg  : 1
//    outgoing msg  : 0
//    sub status    : 1048576
//    status        : 0
//    setting       : hisotry 1 roaming 1 sync 1 count 1 apns_prefix 1 apns_enabled 1 route 1 team_receipt 0 persist 1
//    push content  : [红包]恭喜发财，万事如意
//    push payload  : {
//        sessionID = 5075813000,
//        sessionType = 0
//    }
//    remote ext    : (null)
//    local ext     : (null)
//    client type   : 32
//    anti spam     : (null)
//    ****** NIMMessage End ******
    
//    -[SMP2POpenRedPacketVC doOpenRedPacket]
//    -[SMGroupRedPacketOpenVC doOpenRedPacket]
    
    // 长按图片出现扫码按钮
//    -[NTESSessionViewController recogniseQRCodeImageAtIndex:Image:photoBrowser:]
//    +[LBXScanNative recognizeImage:success:]
//    -[MWPhotoBrowser onLongPressGesture:]
    NSLog(@"receive messages \n%@",messages);
    for (NIMMessage *msg in messages){
        // 红包类型
        if(msg.messageType == 100){
            // 不是自己发送的
            if(!msg.isOutgoingMsg){
                // 未领取
                NIMCustomObject *messageObject = (NIMCustomObject *)msg.messageObject;
                NTESRedPacketAttachment *attachment = (NTESRedPacketAttachment *)messageObject.attachment;
                if(!attachment.isCollected){
                    if(msg.session.sessionType == 0) {// 普通消息
                        OpenRedPacketRequest *req = [objc_getClass("OpenRedPacketRequest") new];
                        req.redPacketId = attachment.redPacketId;
                        req.fromAccid = msg.from;
                        req.originMessageId = msg.messageId;
                        SMC2CRedPacketApiManager *api = [objc_getClass("SMC2CRedPacketApiManager") new];
                        [api asyncOpenRedPacketWithRequest:req callback:^(BOOL success, SMHttpResponse *resp) {
                            if(success || resp.error.code == 304){
                                [[objc_getClass("SMSensorsManager") shareManager]event:@"发送消息" attributes:@{@"message_type":@"private",@"content_type":@"open_ctoc"}];
//                                [SMUTility showAlert:]
                                
                                NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
                                if([userDefaults boolForKey:@"enterChatRoom"]){
                                    UIViewController *viewController = [objc_getClass("SMUTility") topViewController];
                                    // 修复popToRoot后push失败的问题
                                    // https://stackoverflow.com/questions/954982/uinavigationcontroller-poptorootviewcontroller-and-then-immediately-push-a-new
                                    UINavigationController *nav = viewController.navigationController;
                                    if(viewController.presentingViewController){
                                        [viewController dismissViewControllerAnimated:NO completion:^{
                                            
                                        }];
                                    }else{
                                        [nav popToRootViewControllerAnimated:NO];
                                    }
                                    NTESSessionViewController *vc = [[objc_getClass("NTESSessionViewController") alloc]initWithSession:msg.session];
                                    [nav pushViewController:vc animated:NO];
                                }
                            }
                        }];
                    }
                    else{
                        OpenRequest *req = [objc_getClass("OpenRequest") new];
                        req.redPacketId = attachment.redPacketId;
                        req.fromAccid = msg.from;
                        req.originMessageId = msg.messageId;
                        req.sessionId = msg.session.sessionId;
                        req.sessionType = 1;
                        
                        // -[SMGroupRedPacketOpenVC convertRedPacketType:]
                        if(attachment.redPacketType - 1 > 2){
                            req.redPacketType = 0;
                        }else{
                            req.redPacketType = (int)attachment.redPacketType;
                        }
                        SMC2CRedPacketV2ApiManager *api = [objc_getClass("SMC2CRedPacketV2ApiManager") new];
                        [api asyncOpenRedPacketWithRequest:req callback:^(BOOL success, SMHttpResponse *resp) {
                            if(success){
                                [[objc_getClass("SMSensorsManager") shareManager]event:@"发送消息" attributes:@{@"message_type":@"group",@"content_type":@"open_ctoc"}];
                                NIMTeamManager *teamMgr = [objc_getClass("NIMTeamManager") sharedManager];
                                NIMTeam *team = [teamMgr teamById:msg.session.sessionId];
                                [g_speechSynthesizerQueue readLast:[NSString stringWithFormat:@"%@抢到一个红包",team.teamName] withLanguage:@"zh-CN" andRate:0.6];
                                NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
                                if([userDefaults boolForKey:@"enterChatRoom"]){
                                    UIViewController *viewController = [objc_getClass("SMUTility") topViewController];
                                    // 修复popToRoot后push失败的问题
                                    // https://stackoverflow.com/questions/954982/uinavigationcontroller-poptorootviewcontroller-and-then-immediately-push-a-new
                                    UINavigationController *nav = viewController.navigationController;
                                    if(viewController.presentingViewController){
                                        [viewController dismissViewControllerAnimated:NO completion:^{
                                            
                                        }];
                                    }else{
                                        [nav popToRootViewControllerAnimated:NO];
                                    }
                                    NTESSessionViewController *vc = [[objc_getClass("NTESSessionViewController") alloc]initWithSession:msg.session];
                                    [nav pushViewController:vc animated:NO];
                                }
                            }
                        }];
                    }
                }
            }
        }
    }
}

CHDeclareClass(NIMSessionManager)
CHMethod2(void, NIMSessionManager, fetchMessageAttachment, NIMMessage *, msg, didCompleteWithError, NSError *, arg2){
    CHSuper2(NIMSessionManager, fetchMessageAttachment, msg, didCompleteWithError, arg2);
    // 图片类型，自动扫码
    if(!arg2 && msg.messageType == 1){
        if(!msg.isOutgoingMsg){
            NIMImageObject *messageObject = (NIMImageObject *)msg.messageObject;
            UIImage *image = [UIImage imageWithContentsOfFile:messageObject.thumbPath];
            [[objc_getClass("SMScanResultHandler") sharedInstance]recognizeImage:image callback:^(id arg1) {
                NSLog(@"xxxxxxxx");
            }];
        }
    }
}

CHDeclareClass(SMScanResultHandler)
CHMethod1(void, SMScanResultHandler, showJoinGroupAlertWithTeamId, id, arg1){
    // 弹出申请进群的框，直接提交申请
//    CHSuper1(SMScanResultHandler, showJoinGroupAlertWithTeamId, arg1);
    NTESLoginManager *loginMgr = [objc_getClass("NTESLoginManager") sharedManager];
    NSString *nick = loginMgr.currentLoginData.userProfile.nickname;
    NSString *message = [NSString stringWithFormat:@"你好, 我是%@, 求通过",nick];
    [self applyToTeamWithTeamId:arg1 message:message];
}

@interface NTESSessionListViewController : UIViewController
@end

CHDeclareClass(NTESSessionListViewController)
CHMethod0(void, NTESSessionListViewController, viewDidLoad){
    CHSuper0(NTESSessionListViewController, viewDidLoad);
    WMDragView *dragView = [[WMDragView alloc]initWithFrame:CGRectMake(self.view.bounds.size.width - 70, self.view.bounds.size.height - 180, 50, 50)];
    dragView.button.titleLabel.font = [UIFont systemFontOfSize:17.f];
    [dragView.button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    __block BOOL enter = [userDefaults boolForKey:@"enterChatRoom"];
    [dragView.button setTitle:enter?@"开":@"关" forState:UIControlStateNormal];
    [dragView.button setBackgroundColor:enter?[UIColor greenColor]:[UIColor yellowColor]];
//    [dragView.button setBackgroundImage:[UIImage imageNamed:@"AppIcon60x60"] forState:UIControlStateNormal];
    dragView.button.layer.cornerRadius = 25;
    dragView.button.layer.masksToBounds = YES;
    dragView.dragEnable = NO;
    dragView.backgroundColor = [UIColor clearColor];
    dragView.clickDragViewBlock = ^(WMDragView *dragView) {
        enter = !enter;
        [userDefaults setBool:enter forKey:@"enterChatRoom"];
        [userDefaults synchronize];
        [dragView.button setTitle:enter?@"开":@"关" forState:UIControlStateNormal];
        [dragView.button setBackgroundColor:enter?[UIColor greenColor]:[UIColor yellowColor]];
        [objc_getClass("SMUTility") showAlert:[NSString stringWithFormat:@"抢包后自动进群已%@",enter?@"开启":@"关闭"]];
    };
    [self.view addSubview:dragView];
}

CHConstructor
{
    NSLog(@"++++++++ BulletDark loaded ++++++++");
    CHLoadLateClass(NIMChatManager);
    CHHook1(NIMChatManager, onRecvMessages);
    CHLoadLateClass(NIMSessionManager);
    CHHook2(NIMSessionManager, fetchMessageAttachment,didCompleteWithError);
    CHLoadLateClass(SMScanResultHandler);
    CHHook1(SMScanResultHandler, showJoinGroupAlertWithTeamId);
    CHLoadLateClass(NTESSessionListViewController);
    CHHook0(NTESSessionListViewController, viewDidLoad);
    g_speechSynthesizerQueue = [[QHSpeechSynthesizerQueue alloc]init];
}
