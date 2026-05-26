//
//  DIOPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <DIOSDK/DIOORTBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOPlacement : NSObject

@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSMutableArray<DIOAdRequest*> *adRequests;
@property (nonatomic) BOOL showSoundControl;
@property (nonatomic, strong) UIColor *audioAccentColor;
@property (nonatomic, strong) UIColor *audioButtonTextColor;


/**
 @return A new ad request for this placement.
 */
- (DIOAdRequest*)newAdRequest;
/**
 Add a custom ad request to this placement.
 */
- (void)addAdRequest:(DIOAdRequest*)request;


- (void)loadAdFromORTB:(id)ortbResp
     adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
           noAdHandler:(void (^)(NSError*))noAdHandler;

- (instancetype)initWithData:(id)data;
+ (NSString *)placementType;
- (BOOL)hasPendingAdRequests;
- (DIOAdRequest*)lastAdRequest;
- (DIOAdRequest*)adRequestById:(NSString*)requestId;
- (void)removeAdRequestById:(NSString*)requestId;
- (void)finishAllAds;

@end

NS_ASSUME_NONNULL_END
