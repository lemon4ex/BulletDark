//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/NSObject.h>

@class NSError;

@protocol NIMLoginManagerDelegate <NSObject>

@optional
- (void)onMultiLoginClientsChanged;
- (void)onAutoLoginFailed:(NSError *)arg1;
- (void)onLogin:(long long)arg1;
- (void)onKick:(long long)arg1 clientType:(long long)arg2;
@end

