//
//  BulletDark.m
//  BulletDark
//
//  Created by h4ck on 2019/1/17.
//  Copyright (c) 2019年 h4ck. All rights reserved.
//

#import "BulletDark.h"
#import <CaptainHook/CaptainHook.h>
#import "NTESRedPacketManager.h"
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
                    if(msg.session.sessionType == 0) {// 个人
                        OpenRedPacketRequest *req = [objc_getClass("OpenRedPacketRequest") new];
                        req.redPacketId = attachment.redPacketId;
                        req.fromAccid = msg.from;
                        req.originMessageId = msg.messageId;
                        SMC2CRedPacketApiManager *api = [objc_getClass("SMC2CRedPacketApiManager") new];
                        [api asyncOpenRedPacketWithRequest:req callback:^(BOOL success, SMHttpResponse *resp) {
                            if(success || resp.error.code == 304){
                                [[objc_getClass("SMSensorsManager") shareManager]event:@"发送消息" attributes:@{@"message_type":@"private",@"content_type":@"open_ctoc"}];
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
                            }
                        }];
                    }
                }
            }
        }
    }
}

CHConstructor
{
    NSLog(@"++++++++ BulletDark loaded ++++++++");
    CHLoadLateClass(NIMChatManager);
    CHHook1(NIMChatManager, onRecvMessages);
}
