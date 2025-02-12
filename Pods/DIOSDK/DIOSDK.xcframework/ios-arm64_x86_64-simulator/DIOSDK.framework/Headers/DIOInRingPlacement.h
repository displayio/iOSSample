//
//  DIOInRingPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInRingPlacement : DIOPlacement

@property (nonatomic) BOOL isAutoRequestEnabled;
@property (nonatomic) BOOL primerMessage;

- (void)loadInRingFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;


@end

NS_ASSUME_NONNULL_END
