//
//  DIOMockAdapter.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/3/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMockPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOMockAdapter : NSObject

- (void)addPlacement:(DIOMockPlacement*)placement;
- (id)initializationResponse;
- (id)adResponseForPlacementId:(NSString*)ID;

@end

NS_ASSUME_NONNULL_END
