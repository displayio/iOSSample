//
//  DIOInterscrollerPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>
#import <DIOSDK/DIOInterscrollerContainer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerPlacement : DIOPlacement

@property (nonatomic, strong) UIColor *mainBackgrounColor;
@property (nonatomic, strong) UIColor *headerBackgrounColor;
@property (nonatomic, strong) UIColor *headerColor;
@property (nonatomic, strong) NSString *headerText;
@property int interscrollerSize;
@property int interscrollerOffset;
@property (nonatomic) BOOL dynamicHeader;
@property (nonatomic) BOOL reveal;
@property (nonatomic) BOOL showHeader;
@property (nonatomic) BOOL showTapHint;


- (void)loadInterscrollerFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*, DIOInterscrollerContainer*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
