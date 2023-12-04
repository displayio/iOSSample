//
//  DIOPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DIOSDK/DIOORTBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOPlacement : NSObject

@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) id data;
@property (nonatomic, strong) NSMutableArray<DIOAdRequest*> *adRequests;
@property (nonatomic) BOOL defaultMute;
@property (nonatomic) BOOL showSoundControl;


/**
 @return A new ad request for this placement.
 */
- (DIOAdRequest*)newAdRequest;

- (void)loadAdFromORTB:(id)ortbResp
     adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
           noAdHandler:(void (^)(NSError*))noAdHandler;

- (instancetype)initWithId:(NSString*)ID;
- (void)setup:(id)data;
- (BOOL)isOperative;
- (NSString*)name;
- (BOOL)hasPendingAdRequests;
- (DIOAdRequest*)lastAdRequest;
- (DIOAdRequest*)adRequestById:(NSString*)requestId;
- (void)removeAdRequestById:(NSString*)requestId;
- (void)finishAllAds;

@end

NS_ASSUME_NONNULL_END
