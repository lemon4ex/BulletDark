//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NSString;

@interface NIMTeam : NSObject
{
    NSString *_teamId;
    NSString *_teamName;
    NSString *_avatarUrl;
    NSString *_thumbAvatarUrl;
    long long _type;
    NSString *_owner;
    NSString *_intro;
    NSString *_announcement;
    long long _memberNumber;
    long long _level;
    double _createTime;
    long long _joinMode;
    long long _inviteMode;
    long long _beInviteMode;
    long long _updateInfoMode;
    long long _updateClientCustomMode;
    NSString *_serverCustomInfo;
    NSString *_clientCustomInfo;
}

@property(readonly, copy, nonatomic) NSString *clientCustomInfo; // @synthesize clientCustomInfo=_clientCustomInfo;
@property(readonly, copy, nonatomic) NSString *serverCustomInfo; // @synthesize serverCustomInfo=_serverCustomInfo;
@property(nonatomic) long long updateClientCustomMode; // @synthesize updateClientCustomMode=_updateClientCustomMode;
@property(nonatomic) long long updateInfoMode; // @synthesize updateInfoMode=_updateInfoMode;
@property(nonatomic) long long beInviteMode; // @synthesize beInviteMode=_beInviteMode;
@property(nonatomic) long long inviteMode; // @synthesize inviteMode=_inviteMode;
@property(nonatomic) long long joinMode; // @synthesize joinMode=_joinMode;
@property(readonly, nonatomic) double createTime; // @synthesize createTime=_createTime;
@property(readonly, nonatomic) long long level; // @synthesize level=_level;
@property(readonly, nonatomic) long long memberNumber; // @synthesize memberNumber=_memberNumber;
@property(copy, nonatomic) NSString *announcement; // @synthesize announcement=_announcement;
@property(copy, nonatomic) NSString *intro; // @synthesize intro=_intro;
@property(readonly, copy, nonatomic) NSString *owner; // @synthesize owner=_owner;
@property(readonly, nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) NSString *thumbAvatarUrl; // @synthesize thumbAvatarUrl=_thumbAvatarUrl;
@property(copy, nonatomic) NSString *avatarUrl; // @synthesize avatarUrl=_avatarUrl;
@property(copy, nonatomic) NSString *teamName; // @synthesize teamName=_teamName;
@property(readonly, copy, nonatomic) NSString *teamId; // @synthesize teamId=_teamId;
@property(readonly, nonatomic) long long notifyStateForNewMsg;
- (_Bool)inAllMuteMode;
- (id)description;
- (unsigned long long)hash;
- (_Bool)isEqual:(id)arg1;
- (id)initWithProperty:(const struct Property *)arg1;

@end

