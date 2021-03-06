//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NIMMessageObject-Protocol.h"

@class NIMMessageDownloadParam, NSError, NSString;

@protocol NIMMessageObject_Private <NIMMessageObject>
- (void)decodeWithContent:(NSString *)arg1;
- (NSString *)encodeContent;

@optional
- (void)setMessageScene:(NSString *)arg1;
- (NSString *)messageScene;
- (_Bool)shouldIgnoreUnread;
- (void)saveDataAfterReceiving:(_Bool)arg1;
- (NSString *)uploadURL;
- (void)setUploadURL:(NSString *)arg1;
- (NIMMessageDownloadParam *)fileParamForDownload;
- (_Bool)needUpload;
- (NSString *)filepathForUpload;
- (NSError *)prepareForDownLoad;
- (NSError *)prepareForSend;
@end

