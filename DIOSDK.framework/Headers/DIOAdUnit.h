//
//  DIOAdUnit.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OMIDImports.h"

#import "DIOAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOAdUnit : DIOAd

@property (nonatomic, strong) OMIDDisplayioAdSession *omAdSession;

- (instancetype)initWithRequestId:(NSString*)requestId data:(id)data offering:(id)offering;
+ (DIOAdUnit*)factoryWithRequestId:(NSString*)requestId data:(id)data offering:(id)offering;
- (void)renderWithViewController:(UIViewController*)viewController eventHandler:(void (^)(DIOAdEvent event))eventHandler;
- (void)markImpressed;
- (void)callImpressionBeacon;

@end

NS_ASSUME_NONNULL_END
