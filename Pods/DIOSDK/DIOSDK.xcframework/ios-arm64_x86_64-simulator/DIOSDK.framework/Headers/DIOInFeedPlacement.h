//
//  DIOInFeedPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedPlacement : DIOPlacement

@property (nonatomic) BOOL fullWidth;
@property (nonatomic) int customWidth;
@property (nonatomic) BOOL showTimer;
@property (nonatomic, strong) UIColor *frameBackgroundInfeedColor;
@property (nonatomic, strong) UIColor *frameBackgroundHeadlineColor;
@property (nonatomic, strong) UIColor *ctaButtonInfeedColor;
@property (nonatomic, strong) UIColor *ctaButtonHeadlineColor;
@property (nonatomic, strong) UIColor *ctaButtonContourInfeedColor;
@property (nonatomic, strong) UIColor *ctaButtonContourHeadlineColor;
@property (nonatomic, strong) UIColor *ctaButtonTextInfeedColor;
@property (nonatomic, strong) UIColor *ctaButtonTextHeadlineColor;
@property (nonatomic, strong) UIColor *adLabelTextInfeedColor;
@property (nonatomic, strong) UIColor *adLabelTextHeadlineColor;
@property (nonatomic, strong) UIColor *advertiserNameHeadlineColor;
@property (nonatomic, strong) UIColor *bottomLineColor;
@property (nonatomic, strong) UIFont* ctaButtonTextFont;
@property (nonatomic, strong) UIFont* adLabelTextFont;
@property (nonatomic, strong) UIFont* advertiserNameFont;

- (void)loadInfeedFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*))adReceivedHandler
               noAdHandler:(void (^)(NSError*))noAdHandler;


@end

NS_ASSUME_NONNULL_END
