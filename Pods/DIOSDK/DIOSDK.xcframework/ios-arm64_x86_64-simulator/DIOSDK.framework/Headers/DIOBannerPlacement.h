//
//  DIOBannerPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/28/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOBannerPlacement : DIOPlacement
- (void)loadBannerFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
