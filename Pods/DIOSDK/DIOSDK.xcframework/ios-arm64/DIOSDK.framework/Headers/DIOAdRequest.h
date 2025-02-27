//
//  DIOAdRequest.h
//  DIOSDK
//
//  Created by Ro Do on 04.01.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DIOAdUnit.h"
#import "DIOAppData.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOMediationPlatform) {
    DIOMediationPlatformNone = 0,
    DIOMediationPlatformAppLovin = 1,
    DIOMediationPlatformGAM = 2,
    DIOMediationPlatformIronSource = 3
};

typedef NS_ENUM(NSInteger, DIOComplianceState) {
    DIOComplianceStateUnknown = -1,
    DIOComplianceStateNo = 0,
    DIOComplianceStateYes = 1
};

typedef NS_ENUM(NSInteger, DIOGender) {O, M, F};
#define genderArray @"O", @"M", @"F", nil

@interface DIOAdRequest : NSObject

@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *placementId_;
@property (nonatomic, strong, nullable) DIOAd *ad;


/**
 Creates a new ad request. Should not be called directly. Use  placement newAdRequest instead.
 */
- (instancetype)initWithPlacementId:(NSString*)placementId withRequestId:(nullable NSString*)requestId;

/**
 Requests an ad from the server.
 This is an asynchronous operation.
 
 @param adReceivedHandler A block object to be executed when the ad has been received. This block takes one argument: the ad.
 @param noAdHandler A block object to be executed when there is no ad.
 */
- (void)requestAdWithAdReceivedHandler:(void (^)(DIOAd*))adReceivedHandler noAdHandler:(void (^)(NSError*))noAdHandler;
- (void)setPlacementId:(NSString *)placementId;
- (NSMutableDictionary*)body;
+ (nullable NSArray<NSNumber *> *)getGppSid;
/**
 Add ad request data to ad request. Must be set prior to call request ad.
 */

- (void)setTagId:(NSString*)tagId;
- (void)setBcat:(NSArray<NSString*>*)bcat;
- (void)setBadv:(NSArray<NSString*>*)badv;
- (void)setBapp:(NSArray<NSString*>*)bapp;
- (void)setCat:(NSArray<NSString*>*)cat;
- (void)setSectionCats:(NSArray<NSString*>*)sectionCats;
- (void)setPageCat:(NSArray<NSString*>*)pageCat;
- (void)setAppVersion:(NSString*)appVersion;
- (void)setPrivacyPolicy:(NSNumber*)policy;
- (void)setPaid:(NSNumber*)paid;
- (void)setStoreUrl:(NSString*)storeUrl;
- (void)setDomain:(NSString*)domain;
- (void)setPublisherCats:(NSArray<NSString*>*)publisherCats;
- (void)setUserId:(NSString*)userId;
- (void)setBuyerId:(NSString*)buyerId;
- (void)setYob:(NSNumber*)yob;
- (void)setGender:(DIOGender) gender;
- (void)setKeywords:(NSString*)keywords;
- (void)setBidFloor:(NSNumber*)bidFloor;
- (void)setTmax:(NSNumber*)tmax;
- (void)setMediationPlatform:(DIOMediationPlatform) platform;
- (void)setChildCompliant:(DIOComplianceState) complianceState;

- (void)setSKAdNetListMax:(NSNumber*) skadnetlistMax;
- (void)setSKAdNetListExcl:(NSArray<NSNumber*>*) skadnetlistExcl;
- (void)setSKAdNetListAddl:(NSArray<NSString*>*) skadnetlistAddl;
- (void)setSKAdNetListExt:(id) skadnetlistExt;
- (void)setSKProductPage:(NSNumber*) productPage;
- (void)setSKOverlayImp:(NSNumber*) skOverlayImp;
- (void)setSKAdNetVersion:(NSString*) skadnetVersion;
- (void)setSKAdNetVersions:(NSArray<NSString*>*) skadnetVersions;
- (void)setSKAdNetSourceApp:(NSNumber*) skadnetSourceApp;

- (void)setContentId:(NSString*)contentId;
- (void)setContentEpisode:(NSNumber*)episode;
- (void)setContentTitle:(NSString*)title;
- (void)setContentSeries:(NSString*)series;
- (void)setContentSeason:(NSString*)season;
- (void)setContentArtist:(NSString*)artist;
- (void)setContentGenre:(NSString*)genre;
- (void)setContentAlbum:(NSString*)album;
- (void)setContentIsrc:(NSString*)isrc;
- (void)setContentProducer:(DIOContentProducer*)producer;
- (void)setContentUrl:(NSString*)contentUrl;
- (void)setContentCat:(NSArray<NSString*>*)cat;
- (void)setContentProdq:(NSNumber*)prodq;
- (void)setContentContext:(NSNumber*)context;
- (void)setContentRating:(NSString*)contentRating;
- (void)setContentUserrating:(NSString*)contentUserrating;
- (void)setContentQagmediarating:(NSNumber*)qagmediarating;
- (void)setContentKeywords:(NSString*)contentKeywords;
- (void)setContentLivestream:(NSNumber*)livestream;
- (void)setContentSourcerelationship:(NSNumber*)sourcerelationship;
- (void)setContentLen:(NSNumber*)len;
- (void)setContentLanguage:(NSString*)language;
- (void)setContentEmbeddable:(NSNumber*)embeddable;
- (void)setContentData:(NSArray<DIOContentData*>*)contentData;
- (void)addUserEid:(NSString*)eid source:(NSString*)source atype:(NSNumber*)atype;
- (void)setLabel:(NSArray<NSString*>*)label;

@end

NS_ASSUME_NONNULL_END
