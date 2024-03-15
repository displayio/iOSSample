//
//  DIOHeadlinePlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOPlacement.h>
#import <DIOSDK/DIOHeadlineContainer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlinePlacement : DIOPlacement


@property (nonatomic, strong) UIColor *titleInfeedColor;
@property (nonatomic, strong) UIColor *titleHeadlineColor;
@property (nonatomic, strong) UIColor *advertiserNameInfeedColor;
@property (nonatomic, strong) UIColor *advertiserNameHeadlineColor;
@property (nonatomic, strong) UIColor *backgroundInfeedColor;
@property (nonatomic, strong) UIColor *backgroundHeadlineColor;
@property (nonatomic, strong) UIColor *buttonBackgroundInfeedColor;
@property (nonatomic, strong) UIColor *buttonBackgroundHeadlineColor;
@property (nonatomic, strong) UIColor *buttonTextInfeedColor;
@property (nonatomic, strong) UIColor *buttonTextHeadlineColor;
@property (nonatomic, strong) UIColor *buttonContourInfeedColor;
@property (nonatomic, strong) UIColor *buttonContourHeadlineColor;
@property (nonatomic, strong) UIColor *swipeOffLineColor;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *buttonText;
@property (nonatomic) BOOL showAdvertiser;
@property (nonatomic) NSInteger headlineModeDuration;


- (void)loadHeadlineFromORTB:(id)ortbResp
         adReceivedHandler:(void (^)(DIOAd*, DIOHeadlineContainer*))adReceivedHandler
                 noAdHandler:(void (^)(NSError*))noAdHandler;
@end

NS_ASSUME_NONNULL_END
