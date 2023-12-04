//
//  DIOInterstitialPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialPlacement : DIOPlacement

- (void)loadInterstitialFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
