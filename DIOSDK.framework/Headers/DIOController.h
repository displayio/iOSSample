//
//  DIOController.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/17/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "DIOPlacement.h"
#import "DIOServiceClient.h"
#import "DIOMockAdapter.h"
#import "DIOConsentManager.h"
#import "DIOInitProperties.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOErrorCode) {
    kDIOErrorMisc = 0,
    kDIOErrorNoDataSectionInResponse = 1,
    kDIOErrorNoPlacementsSectionInResponse = 2,
    kDIOErrorUnknownPlacementType = 3,
    kDIOErrorLoadingProviderMoreThanOnce = 4,
    kDIOErrorNoFill = 5,
    kDIOErrorNoAds = 6,
    kDIOErrorNoAd = 7,
    kDIOErrorAdUnavailable = 8,
    kDIOErrorParsing = 9
};

typedef NS_ENUM(NSInteger, DIOMediationPlatform) {
    DIOMediationPlatformNone = 0,
    DIOMediationPlatformMopub = 1,
    DIOMediationPlatformAdmob = 2
};

extern NSString* const ERROR_LEVEL_WARN;
extern NSString* const ERROR_LEVEL_FATAL;
extern NSString* const ERROR_LEVEL_ERROR;
extern NSString* const ERROR_LEVEL_TRACKING_ERROR;

@interface DIOController : NSObject <CLLocationManagerDelegate>

@property (nonatomic) BOOL initialized;
@property (nonatomic, strong) NSMutableDictionary *placements;
@property (nonatomic, strong) CLLocation *lastKnownLocation;
@property (nonatomic) DIOMediationPlatform mediationPlatform;
@property (nonatomic, getter=isMocking) BOOL mocking;
@property (nonatomic) int impTrackingPercent;
@property (nonatomic) int impTrackingDelay;

/**
 @return The DIOController singleton.
 */
+ (DIOController*)sharedInstance;

/**
 Initializes the DIOController. This should be called only once during the application lifecycle.
 
 This operation is asynchronous.
 
 @param properties A DIOInitProperties object containing predefined properties. Can be nil.
 @param appId The application id as defined in the Display.io control panel.
 @param completionHandler A block object to be executed when the task finishes successfully.
 @param errorHandler A block object to be executed when something is going wrong. This block takes one argument: the error.
 */
- (void)initializeWithProperties:(nullable DIOInitProperties*)properties appId:(NSString*)appId completionHandler:(void (^)(void))completionHandler errorHandler:(void (^)(NSError*))errorHandler;

/**
 @param placementId The placement id as defined in the Display.io control panel.
 
 @return The corresponding placement object or nil if DIOController is not initialized or if no placement object is found.
*/
- (DIOPlacement*)placementWithId:(NSString*)placementId;

/**
Stops all ads and releases the resources associated with each of them
*/
- (void)finishAllAds;

/**
 Allows to control if location based targeting should be used (enabled by default.)
 
 @param enabled Whether to enable or not.
 */
- (void)setLocationBasedTargeting:(BOOL)enabled;

- (NSString*)appId;
- (DIOInitProperties*)initializationProperties;
- (NSString*)userSession;
- (DIOServiceClient*)serviceClient;
- (DIOMockAdapter*)mockAdapter;

- (id)iabConsentData;
- (void)clearIABConsentData;
- (id)consentData;
- (void)setConsentData:(DIOConsentState) consentState gdprState:(DIOConsentState) gdprState;

- (void)logWithMessage:(NSString*)message;
- (void)logWithError:(NSString*)error trace:(NSArray<NSString*>*)trace data:(id)data level:(NSString*)level;

- (void)uninitialize;
- (void)setCourseWithURLString:(NSString*)urlString;
- (void)setHyperGeoWithIp:(NSString*)ip;
- (void)handleUncaughtException:(NSException*)exception;
- (void)crash;

@end

NS_ASSUME_NONNULL_END
