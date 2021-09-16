//
//  DIOInterscrollerPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerPlacement : DIOPlacement

@property (nonatomic, strong) UIColor *mainBackgrounColor;
@property (nonatomic, strong) UIColor *headerBackgrounColor;
@property (nonatomic, strong) UIColor *headerColor;
@property (nonatomic, strong) UIColor *footerBackgrounColor;
@property (nonatomic, strong) UIColor *footerColor;
@property int interscrollerSize;
@property int interscrollerOffset;
@property bool dynamicHeader;
@end

NS_ASSUME_NONNULL_END
