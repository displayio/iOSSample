//
//  DIOInlinePlacement.h
//  DIOSDK
//
//  Created by Roman Do on 05.11.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#import <DIOSDK/DIOSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInlinePlacement : DIOPlacement

- (DIOPlacement*) getSubPlacement:(NSString*)adUnit;

- (void)loadInlineFromORTB:(id)ortbResp 
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
