//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/NSObject.h>

#import "NIMLoginManagerDelegate.h"
#import "NIMTeamManagerDelegate.h"
#import "NIMUserManagerDelegate.h"

@class NSMutableSet, NSObject<OS_dispatch_queue>, NSObject<OS_dispatch_semaphore>, NSString;

@interface SMContactManager : NSObject <NIMUserManagerDelegate, NIMTeamManagerDelegate, NIMLoginManagerDelegate>
{
    NSObject<OS_dispatch_semaphore> *_semaphore;
    NSObject<OS_dispatch_queue> *_refreshQueue;
    NSObject<OS_dispatch_queue> *_loadDatasQueue;
    _Bool _initFinished;
    _Bool _contactsLoaded;
    id/*CDUnknownBlockType*/ _callback;
    NSMutableSet *_allContacts;
}

+ (void)renameDatabaseFiles;
+ (void)resetCoreDataDB;
+ (void)setupDatabase;
+ (id)shareManager;
@property(nonatomic) _Bool contactsLoaded; // @synthesize contactsLoaded=_contactsLoaded;
@property(retain, nonatomic) NSMutableSet *allContacts; // @synthesize allContacts=_allContacts;
@property(nonatomic) _Bool initFinished; // @synthesize initFinished=_initFinished;
@property(copy, nonatomic) id/*CDUnknownBlockType*/ callback; // @synthesize callback=_callback;
- (void)didReceiveMemoryWarning;
- (void)postNotificationName:(id)arg1 object:(id)arg2 userInfo:(id)arg3;
- (void)postNotificationName:(id)arg1 object:(id)arg2;
- (void)SMContactChangedPush:(id)arg1;
- (void)networkChangedFromUnreachablegout:(id)arg1;
- (void)contactStoreDidChangeNotification:(id)arg1;
- (void)onTeamMembersHasUpdatedNotification:(id)arg1;
- (void)onBlackListChanged;
- (void)onTeamUpdated:(id)arg1;
- (void)onTeamRemoved:(id)arg1;
- (void)onTeamAdded:(id)arg1;
- (void)onFriendChanged:(id)arg1;
- (void)onUserInfoChanged:(id)arg1;
- (void)applicationWillEnterForeground:(id)arg1;
- (void)SMLoginSuccess:(id)arg1;
- (void)logout:(id)arg1;
- (void)onLogin:(long long)arg1;
- (id)filterRecentMemberWithConfig:(id)arg1;
- (void)removeObjects:(id)arg1;
- (void)removeObject:(id)arg1;
- (void)addObjects:(id)arg1;
- (void)addObject:(id)arg1;
- (void)removeModelWithMobile:(id)arg1;
- (void)removeModelWithInfoId:(id)arg1;
- (id)getInfoOfTeamCustomExt:(id)arg1;
- (id)getInfoOfTeamExtension:(id)arg1;
- (id)getInfoOfUserExtension:(id)arg1;
- (id)contactUserForMobile:(id)arg1;
- (id)contactUserForUserId:(id)arg1;
- (void)updateMobiles:(id)arg1 invitedDate:(id)arg2;
- (void)updateMobiles:(id)arg1 hasInvited:(_Bool)arg2;
- (void)updateMobile:(id)arg1 recordUrl:(id)arg2;
- (void)updateContact:(id)arg1 blackList:(_Bool)arg2 callBack:(id/*CDUnknownBlockType*/)arg3;
- (void)updateContact:(id)arg1 alias:(id)arg2 callBack:(id/*CDUnknownBlockType*/)arg3;
- (void)updateContact:(id)arg1 star:(_Bool)arg2 isTeam:(_Bool)arg3 callBack:(id/*CDUnknownBlockType*/)arg4;
- (void)updateContactWithMobile:(id)arg1 star:(_Bool)arg2 callBack:(id/*CDUnknownBlockType*/)arg3;
- (void)updateContactWithMobile:(id)arg1 userProfile:(id)arg2;
- (id)modelsWithPredicate:(id)arg1;
- (id)modelsWithMobile:(id)arg1;
- (id)modelsWithTeamId:(id)arg1;
- (id)modelsWithUserId:(id)arg1;
- (void)updateTeam:(id)arg1;
- (void)removeTeam:(id)arg1;
- (void)addTeam:(id)arg1;
- (void)updateUser:(id)arg1;
- (void)removeUser:(id)arg1;
- (void)addUser:(id)arg1;
- (id)matchPinYinWithConfig:(id)arg1 inMembers:(id)arg2;
- (void)filterArray:(id)arg1 withConfig:(id)arg2;
- (void)sortByDefault:(id)arg1 callback:(id/*CDUnknownBlockType*/)arg2;
- (void)sortByContactTimes:(id)arg1 callback:(id/*CDUnknownBlockType*/)arg2;
- (void)sortByAddTime:(id)arg1 callback:(id/*CDUnknownBlockType*/)arg2;
- (void)sortByAll:(id)arg1 callback:(id/*CDUnknownBlockType*/)arg2;
- (void)sortArray:(id)arg1 refreshStyle:(long long)arg2 callback:(id/*CDUnknownBlockType*/)arg3;
- (void)refreshFriendsChange;
- (id)incomeDailyNumberModel;
- (id)publicNumberModel;
- (id)fileTransferModel;
- (void)loadDatasFromSource:(long long)arg1 completionHandler:(id/*CDUnknownBlockType*/)arg2;
- (void)searchMembersWithConfig:(id)arg1 callBack:(id/*CDUnknownBlockType*/)arg2;
- (void)getMembersWithConfig:(id)arg1 callBack:(id/*CDUnknownBlockType*/)arg2;
- (id)getAllPhoneContactsFromDB;
- (id)getAllPhoneContacts;
- (id)getAllNIMTeamsFromDB;
- (id)getAllNIMTeams;
- (id)getAllNIMUsersFromDB;
- (id)getAllPublicAccounts;
- (id)getAllNIMUsers;
- (void)mergeModel:(id)arg1 toModel:(id)arg2;
- (_Bool)didInitFinished;
- (void)matchPhoneContactsFromServer;
- (void)syncUserFromContactStore;
- (void)syncUsersAccidFromServer;
- (void)syncUserDBFromNIMDB;
- (void)onNIMLogin;
- (unsigned long long)totalCount;
- (long long)unfamilierCount;
- (void)requestAuthorization:(id/*CDUnknownBlockType*/)arg1;
- (void)initDatas;
- (id)init;
- (void)dealloc;
- (void)addNotifications;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

