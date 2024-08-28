//
//  DIODeviceData.h
//  DIOSDK
//
//  Created by Ro Do on 05.01.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIODeviceData : NSObject
- (NSMutableDictionary*)body;
- (void)updateGeo;
- (BOOL)isGeoSupported;
@end

NS_ASSUME_NONNULL_END
