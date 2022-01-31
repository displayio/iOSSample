//
//  DIOHeadlinePlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlinePlacement : DIOPlacement

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *backgroundColorSnap;
@property (nonatomic, strong) UIColor *color;
@property (nonatomic, strong) UIColor *colorSnap;

@end

NS_ASSUME_NONNULL_END
