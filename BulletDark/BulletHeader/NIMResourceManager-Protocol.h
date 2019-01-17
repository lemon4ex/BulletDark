//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NIMResourceQueryOption, NSString;

@protocol NIMResourceManager <NSObject>
- (void)removeResourceFiles:(NIMResourceQueryOption *)arg1 completion:(void (^)(NSError *, long long))arg2;
- (void)searchResourceFiles:(NIMResourceQueryOption *)arg1 completion:(void (^)(NSError *, NSArray *))arg2;
- (NSString *)videoThumbnailURL:(NSString *)arg1;
- (NSString *)imageThumbnailURL:(NSString *)arg1;
- (NSString *)convertURLToAcceleratedURL:(NSString *)arg1;
- (NSString *)convertHttpToHttps:(NSString *)arg1;
- (NSString *)normalizeURLString:(NSString *)arg1;
- (void)cancelTask:(NSString *)arg1;
- (void)download:(NSString *)arg1 filepath:(NSString *)arg2 progress:(void (^)(float))arg3 completion:(void (^)(NSError *))arg4;
- (void)upload:(NSString *)arg1 scene:(NSString *)arg2 progress:(void (^)(float))arg3 completion:(void (^)(NSString *, NSError *))arg4;
- (void)upload:(NSString *)arg1 progress:(void (^)(float))arg2 completion:(void (^)(NSString *, NSError *))arg3;
@end
