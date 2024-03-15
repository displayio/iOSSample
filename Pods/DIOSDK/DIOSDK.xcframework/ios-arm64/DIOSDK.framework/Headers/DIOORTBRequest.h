//
//  DIOORTBRequest.h
//  DIOSDK
//
//  Created by Ro Do on 25.04.2023.
//  Copyright © 2023 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOORTBRequest : DIOAdRequest
- (void)requestAdForORTB: (id)ortbResp
                     adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
                           noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
