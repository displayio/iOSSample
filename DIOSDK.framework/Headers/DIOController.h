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
#import "DIOConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOCompliance) {
    DIOComplianceUnknown = -1,
    DIOComplianceNo = 0,
    DIOComplianceYes = 1
};

typedef NS_ENUM(NSInteger, DIOMediationPlatform) {
    DIOMediationPlatformNone = 0,
    DIOMediationPlatformMopub = 1,
    DIOMediationPlatformAdmob = 2
};

@interface DIOController : NSObject <CLLocationManagerDelegate>

@property (nonatomic) BOOL initialized;
@property (nonatomic, strong) NSMutableDictionary *placements;
@property (nonatomic, strong) CLLocation *lastKnownLocation;

@property (nonatomic) DIOCompliance coppaCompliant;
@property (nonatomic) DIOCompliance GDPRChildCompliant;
@property (nonatomic) DIOMediationPlatform mediationPlatform;

/**
 @return The DIOController singleton.
 */
+ (DIOController*)sharedInstance;

/**
 Initializes the DIOController. This should be called only once during the application lifecycle.
 
 This operation is asynchronous.
 
 @param appId The application id as defined in the Display.io control panel.
 @param completionHandler A block object to be executed when the task finishes successfully.
 @param errorHandler A block object to be executed when something is going wrong. This block takes one argument: the error message.
 */
- (void)initializeWithAppId:(NSString*)appId completionHandler:(void (^)(void))completionHandler errorHandler:(void (^)(NSString*))errorHandler;

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
 
 Should be called before -initializeWithAppId:completionHandler:errorHandler:
 
 @param enabled Whether to enable or not.
 */
- (void)setLocationBasedTargeting:(BOOL)enabled;

/**
 Allows to control if first call to Display.io server should use https protocol
 (otherwise http will be used)
 
 Should be called before -initializeWithAppId:completionHandler:errorHandler:
 */
- (void)requireHttpsInitialization;

- (NSString*)appId;
- (DIOServiceClient*)serviceClient;
- (id)consentData;
- (id)iabConsentData;
- (void)setConsentData:(DIOConsentState) consentState gdprState:(DIOConsentState) gdprState;
- (void)logWithMessage:(NSString*)message;
- (void)logWithError:(NSString*)error trace:(NSArray<NSString*>*)trace data:(id)data;

- (void)uninitialize;
- (void)setCourseWithURLString:(NSString*)urlString;
- (void)setHyperGeoWithIp:(NSString*)ip;
- (void)handleUncaughtException:(NSException*)exception;
- (BOOL)shouldApplyGDPRConstraints;
- (BOOL)shouldApplyCOPPACompliance;
- (BOOL)shouldApplyGDPRChildCompliance;
- (BOOL)doesRequireHttpsInit;

@end

NS_ASSUME_NONNULL_END
