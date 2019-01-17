//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//
#import "SMUserProfile.h"

@class NSString, SMUserProfile;

@interface LoginData : NSObject <NSCoding>
{
    NSString *_accid;
    NSString *_token;
    NSString *_smAccessToken;
    NSString *_smDeviceToken;
    SMUserProfile *_userProfile;
}

@property(retain, nonatomic) SMUserProfile *userProfile; // @synthesize userProfile=_userProfile;
@property(copy, nonatomic) NSString *smDeviceToken; // @synthesize smDeviceToken=_smDeviceToken;
@property(copy, nonatomic) NSString *smAccessToken; // @synthesize smAccessToken=_smAccessToken;
@property(copy, nonatomic) NSString *token; // @synthesize token=_token;
@property(copy, nonatomic) NSString *accid; // @synthesize accid=_accid;
- (void)saveToDB;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end
