//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "NIMCustomAttachment.h"
#import "NTESCustomAttachmentInfo.h"

@class NSString;

@interface NTESRedPacketAttachment : NSObject <NIMCustomAttachment, NTESCustomAttachmentInfo>
{
    _Bool _isCollected;
    NSString *_redPacketId;
    NSString *_title;
    NSString *_content;
    unsigned long long _redPacketStatus;
    unsigned long long _redPacketType;
}

@property(nonatomic) _Bool isCollected; // @synthesize isCollected=_isCollected;
@property(nonatomic) unsigned long long redPacketType; // @synthesize redPacketType=_redPacketType;
@property(nonatomic) unsigned long long redPacketStatus; // @synthesize redPacketStatus=_redPacketStatus;
@property(copy, nonatomic) NSString *content; // @synthesize content=_content;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *redPacketId; // @synthesize redPacketId=_redPacketId;
- (_Bool)canBeRevoked;
- (_Bool)canBeForwarded;
- (id)cellContent:(id)arg1;
- (struct UIEdgeInsets)contentViewInsets:(id)arg1;
- (struct CGSize)contentSize:(id)arg1 cellWidth:(double)arg2;
- (id)encodeAttachment;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

