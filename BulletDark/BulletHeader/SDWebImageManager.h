//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NSMutableArray, NSMutableSet, SDImageCache, SDWebImageDownloader;
@protocol SDWebImageManagerDelegate;

@interface SDWebImageManager : NSObject
{
    id <SDWebImageManagerDelegate> _delegate;
    SDImageCache *_imageCache;
    SDWebImageDownloader *_imageDownloader;
    id/*CDUnknownBlockType*/ _cacheKeyFilter;
    NSMutableSet *_failedURLs;
    NSMutableArray *_runningOperations;
}

+ (id)sharedManager;
@property(retain, nonatomic) NSMutableArray *runningOperations; // @synthesize runningOperations=_runningOperations;
@property(retain, nonatomic) NSMutableSet *failedURLs; // @synthesize failedURLs=_failedURLs;
@property(copy, nonatomic) id/*CDUnknownBlockType*/ cacheKeyFilter; // @synthesize cacheKeyFilter=_cacheKeyFilter;
@property(retain, nonatomic) SDWebImageDownloader *imageDownloader; // @synthesize imageDownloader=_imageDownloader;
@property(retain, nonatomic) SDImageCache *imageCache; // @synthesize imageCache=_imageCache;
@property(nonatomic) __weak id <SDWebImageManagerDelegate> delegate; // @synthesize delegate=_delegate;
- (_Bool)isRunning;
- (void)cancelAll;
- (void)saveImageToCache:(id)arg1 forURL:(id)arg2;
- (id)downloadImageWithURL:(id)arg1 options:(unsigned long long)arg2 progress:(id/*CDUnknownBlockType*/)arg3 completed:(void(^)(UIImage * image, NSData * data, NSError * error, NSInteger cacheType, BOOL finished, NSURL * imageURL))arg4;
- (void)diskImageExistsForURL:(id)arg1 completion:(id/*CDUnknownBlockType*/)arg2;
- (void)cachedImageExistsForURL:(id)arg1 completion:(id/*CDUnknownBlockType*/)arg2;
- (_Bool)diskImageExistsForURL:(id)arg1;
- (_Bool)cachedImageExistsForURL:(id)arg1;
- (id)cacheKeyForURL:(id)arg1;
- (id)createCache;
- (id)init;
- (id)downloadWithURL:(id)arg1 options:(unsigned long long)arg2 progress:(id/*CDUnknownBlockType*/)arg3 completed:(id/*CDUnknownBlockType*/)arg4;

@end

