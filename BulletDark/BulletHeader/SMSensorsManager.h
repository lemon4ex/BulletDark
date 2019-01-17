//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "NIMChatManagerDelegate.h"

@class NSDictionary, NSString;

@interface SMSensorsManager : NSObject <NIMChatManagerDelegate>
{
    NSDictionary *_timeEventKeysDict;
    NSDictionary *_actionEventKeysDict;
    NSDictionary *_userProperties;
    NSDictionary *_eventProperties;
}

+ (void)setFirstTimeForKey:(id)arg1;
+ (_Bool)isFirstTimeForKey:(id)arg1;
+ (id)shareManager;
@property(retain, nonatomic) NSDictionary *eventProperties; // @synthesize eventProperties=_eventProperties;
@property(retain, nonatomic) NSDictionary *userProperties; // @synthesize userProperties=_userProperties;
@property(retain, nonatomic) NSDictionary *actionEventKeysDict; // @synthesize actionEventKeysDict=_actionEventKeysDict;
@property(retain, nonatomic) NSDictionary *timeEventKeysDict; // @synthesize timeEventKeysDict=_timeEventKeysDict;
- (void)setLoginTimeForSensor;
- (void)updateLastVersion;
- (void)clearUnUsedProperties;
- (void)pointForOpenApp;
- (void)setUpWithLaunchOptions:(id)arg1;
- (id)sensorsProperties;
- (void)setEventCommonProperties:(id)arg1;
- (void)setCommonProperties:(id)arg1;
- (void)login:(id)arg1;
- (void)endEvent:(id)arg1 withProps:(id)arg2;
- (void)endEvent:(id)arg1;
- (void)beginEvent:(id)arg1;
- (void)webEvemt:(id)arg1 attributes:(id)arg2;
- (void)event:(id)arg1 attributes:(id)arg2;
- (void)loadKeys;
- (id)init;
- (id)messageDict;
- (id)getContentTypeByMessage:(id)arg1;
- (void)sendMessage:(id)arg1 didCompleteWithError:(id)arg2;
- (void)setUpMessageDelegate;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

