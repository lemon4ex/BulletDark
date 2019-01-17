//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "SMBaseApiManager.h"

@class C2CRedPacket, SMHttpResponse;

@interface SMC2CRedPacketApiManager : SMBaseApiManager
{
//    C2CRedPacket *_grpcService;
}

@property(readonly, nonatomic) C2CRedPacket *grpcService; // @synthesize grpcService=_grpcService;
- (void)asyncCheckUserInWhiteListWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (void)asyncFetchRedPacketListWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (void)asyncFetchRedPacketInfoWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (void)asyncOpenRedPacketWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (void)asyncGrabRedPacketWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (void)asyncCreateRedPacketOrderWithRequest:(id)arg1 callback:(void(^)(BOOL success,SMHttpResponse *resp))arg2;
- (id)host;
- (id)init;

@end

