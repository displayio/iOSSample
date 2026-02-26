//
//  DIOMediumRectanglePlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 12/15/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("MediumRectangle placement is deprecated. Use InFeed instead.")
@interface DIOMediumRectanglePlacement : DIOPlacement
- (void)loadMRectFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
