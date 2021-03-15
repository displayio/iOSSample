//
//  DIOAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOAdEvent) {
    DIOAdEventOnShown,
    DIOAdEventOnFailedToShow,
    DIOAdEventOnClicked,
    DIOAdEventOnClosed,
    DIOAdEventOnAdCompleted
};

@class DIOAd;

@protocol DIOAdClickDelegate <NSObject>

- (void)onAdClicked:(DIOAd*)ad;

@end

@interface DIOAd : NSObject

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic, strong) NSString *requestId;
@property (nonatomic, strong) NSString *format;
@property (nonatomic, strong) id data;
@property (nonatomic, strong) id offering;
@property (nonatomic, strong) NSString *ID;
@property (nonatomic) BOOL loaded;
@property (nonatomic) BOOL impressed;
@property (nonatomic) BOOL isInterstitial;
@property (nonatomic) BOOL isRewardedVideo;
@property (nonatomic) BOOL isInFeed;
@property (nonatomic) BOOL isEndCard;
@property (nonatomic) BOOL isInterscroller;
@property (nonatomic) BOOL isBanner;
@property (nonatomic) BOOL isMediumRectangle;
@property (nonatomic) BOOL isOutstreamVideo;
@property (nonatomic, strong) NSString *advertiserName;
@property (nonatomic, strong) NSString *advertiserClickURL;
@property (nonatomic, weak) id<DIOAdClickDelegate> clickDelegate;

@property (nonatomic, strong) void (^adEventHandler)(DIOAdEvent);

@property (nonatomic) BOOL scaleWebviewToAd;
@property (nonatomic) BOOL isSticky;
@property (nonatomic) NSInteger holdPeriod;

/**
 Shows an interstitial ad.
 
 @param controller The current view controller.
 @param eventHandler A block object to be executed when an event occur. This block takes one argument: the event type.
 @see DIOAdEvent enum
 */
- (void)showAdFromViewController:(UIViewController*)controller eventHandler:(void (^)(DIOAdEvent event))eventHandler;

/**
Use to track events for InFeed, Banner, Medium Rectangle, Interscroller and OutStream Video. NOTE: do not use for Interstitial or Rewarded Video ads, the proper method to track its events is using showAdFromViewController 
@method showAdFromViewController
*/
- (void)setEventHandler:(void (^)(DIOAdEvent event))eventHandler;

/**
 Leaves ad's current screen (for in-feed video ads only)
 */
- (void)leave;

/**
 Re-enters ad's current screen (for in-feed video ads only)
 */
- (void)reenter;

/**
 Stops an ad and releases the resources associated with it
 */
- (void)finish;

/**
 */
- (UIView*)view;

- (UIViewController*)viewController;
- (void)preloadWithLoadedHandler:(void (^)(void))loadedHandler errorHandler:(void (^)(NSError*))errorHandler noFillHandler:(void (^)(void))noFillHandler;

@end

NS_ASSUME_NONNULL_END
