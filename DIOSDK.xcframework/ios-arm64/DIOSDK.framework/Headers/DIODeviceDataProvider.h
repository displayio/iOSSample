//
//  DIODeviceDataProvider.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIODeviceDataProvider : NSObject

+ (id)deviceHardwareData;
+ (id)deviceAdId;
+ (BOOL)isAdvertisingTrackingEnabled;

+ (NSNumber*)appTrackingTransparencyFrameworkStatus;
+ (NSArray*)skAdNetworkItems;
+ (NSString*)identifierForVendor;


@end

NS_ASSUME_NONNULL_END
