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

NS_ASSUME_NONNULL_BEGIN

@interface DIOAdUnit : DIOAd

@property (nonatomic, strong) DIOOMAdSession* omAdSession;

@property (nonatomic) BOOL watermarked;
@property (nonatomic) BOOL wasMeasuredImpressionAttempt;

@property (nonatomic, copy) void (^loadedHandler)(void);
@property (nonatomic, copy) void (^noFillHandler)(void);
@property (nonatomic, copy) void (^errorHandler)(NSError*);

- (instancetype)initWithRequestId:(NSString*)requestId data:(id)data offering:(id)offering;
+ (DIOAdUnit*)factoryWithRequestId:(NSString*)requestId data:(id)data offering:(id)offering;
- (void)renderWithViewController:(UIViewController*)viewController eventHandler:(void (^)(DIOAdEvent event))eventHandler;
- (void)didTransitionToSize:(CGSize)size;
- (void)markImpressed;
- (void)callImpressionBeacon;
- (void)callAdLoadBeacon;
- (void)close;
- (void)broadcastLoaded;
- (void)broadcastNoFill;
- (void)broadcastError:(NSError*)error;
- (void)registerMRCImpression:(int) delay;
- (NSString*) generateImpBeacon;
- (bool)doRedirect:(NSString*)urlString responder:(UIResponder*) responder;
@end

NS_ASSUME_NONNULL_END
