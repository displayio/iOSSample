//
//  DIOInterscrollerMockPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/3/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMockPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerMockPlacement : DIOMockPlacement

@property (nonatomic) BOOL sticky;
@property (nonatomic) BOOL reveal;
@property (nonatomic) double holdDuration;

@end

NS_ASSUME_NONNULL_END
