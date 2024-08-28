//
//  DIOInterscrollerPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerPlacement : DIOPlacement

@property (nonatomic, strong) UIColor *mainBackgrounColor;
@property (nonatomic, strong) UIColor *headerBackgrounColor;
@property (nonatomic, strong) UIColor *headerColor;
@property (nonatomic, strong) NSString *headerText;
@property (nonatomic, strong) UIColor *footerBackgrounColor;
@property (nonatomic, strong) UIColor *footerColor;
@property (nonatomic, strong) UIView *topOverlappingView;
@property (nonatomic, strong) UIFont *headerFont;
@property int interscrollerSize;
@property int interscrollerOffset;
@property (nonatomic) BOOL dynamicHeader;
@property (nonatomic) BOOL reveal;
@property (nonatomic) BOOL showHeader;
@property (nonatomic) BOOL showTapHint;


- (void)loadInterscrollerFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
