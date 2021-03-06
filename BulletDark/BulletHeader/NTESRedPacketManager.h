//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "SMRedPacketDelegate.h"

@class NIMMessageModel, NIMSession, NSString;

@interface NTESRedPacketManager : NSObject <SMRedPacketDelegate>
{
    NIMSession *_currentSession;
    NIMMessageModel *_currentMessageModel;
    id/*CDUnknownBlockType*/ _refreshMessageViewBlock;
    id/*CDUnknownBlockType*/ _stateCallback;
}

+ (id)sharedManager;
@property(copy, nonatomic) id/*CDUnknownBlockType*/ stateCallback; // @synthesize stateCallback=_stateCallback;
@property(copy, nonatomic) id/*CDUnknownBlockType*/ refreshMessageViewBlock; // @synthesize refreshMessageViewBlock=_refreshMessageViewBlock;
- (id)currentTopViewController;
- (void)checkAlipayBeforeBizProcessing:(id/*CDUnknownBlockType*/)arg1 forEntranceType:(unsigned long long)arg2;
- (void)showB2CRedPacketDetail:(id)arg1 session:(id)arg2 refreshViewBlock:(id/*CDUnknownBlockType*/)arg3;
- (void)showC2CRedPacketDetail:(id)arg1 session:(id)arg2 refreshViewBlock:(id/*CDUnknownBlockType*/)arg3;
- (void)openB2CRedPacketFromMessageModel:(id)arg1 session:(id)arg2 refreshViewBlock:(id/*CDUnknownBlockType*/)arg3;
- (void)origin_openC2CRedPacketFromMessageModel:(id)arg1 session:(id)arg2 refreshViewBlock:(id/*CDUnknownBlockType*/)arg3;
- (void)openC2CRedPacketFromMessageModel:(id)arg1 session:(id)arg2 refreshViewBlock:(id/*CDUnknownBlockType*/)arg3;
- (void)sendRedPacket:(id)arg1;
- (void)origin_sendRedPacket:(id)arg1 stateCallBack:(id/*CDUnknownBlockType*/)arg2;
- (void)sendRedPacket:(id)arg1 stateCallBack:(id/*CDUnknownBlockType*/)arg2;
- (id)init;
- (void)updateB2CRedPacketStatus:(unsigned long long)arg1;
- (void)redPacketSend:(_Bool)arg1;
- (void)updateGroupRedPacketStatus:(unsigned long long)arg1 isCollected:(_Bool)arg2;
- (void)updateRedPacketStatus:(unsigned long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

