//
//  DIOInterstitialPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialPlacement : DIOPlacement
@property (nonatomic, assign) NSInteger skippableIn;
@property (nonatomic, assign) NSInteger closeButtonDelay;

- (void)loadInterstitialFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
