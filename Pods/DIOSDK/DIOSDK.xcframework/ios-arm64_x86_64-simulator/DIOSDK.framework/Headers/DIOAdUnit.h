//
//  DIOAdUnit.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DIOSDK/DIOAd.h>
#import <DIOSDK/DIOOMAdSession.h>
#import <DIOSDK/DIOEndCard.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOAdUnit : DIOAd

@property (nonatomic, strong) DIOOMAdSession* omAdSession;
@property (nonatomic, strong, nullable) DIOEndCard *endCard;

@property (nonatomic) BOOL wasMeasuredImpressionAttempt;

@property (nonatomic, copy) void (^loadedHandler)(void);
@property (nonatomic, copy) void (^noFillHandler)(void);
@property (nonatomic, copy) void (^errorHandler)(NSError*);
@property (nonatomic, strong) NSString *dioImp;

@property (nonatomic) int impTrackingPercent;
@property (nonatomic) int dwellTime;
@property (nonatomic) int rewarded;
@property (nonatomic) int omidStart;
@property (nonatomic) int omidImp;

- (instancetype)initWithData:(id)data;
+ (DIOAdUnit*)factoryWithData:(id)data;
- (void)renderWithViewController:(UIViewController*)viewController eventHandler:(void (^)(DIOAdEvent event))eventHandler;
- (void)didTransitionToSize:(CGSize)size;
- (void)markImpressed;
- (void)callImpressionBeacon;
- (void)callMetricTracking:(NSString*)metric;
- (void)close;
- (void)broadcastLoaded;
- (void)broadcastNoFill;
- (void)broadcastError:(NSError*)error;
- (void)registerMRCImpression:(int) delay;
- (bool)doRedirect:(NSString*)urlString responder:(UIResponder*) responder;
- (void)showSKOverlay;
- (void)dismissSKOverlay;
- (void)prepareSKStoreProductViewController:(NSString*)urlString;
-(NSString*)clickTrackingBeacon;
- (BOOL)isEndcardAvailable;

@end

NS_ASSUME_NONNULL_END
