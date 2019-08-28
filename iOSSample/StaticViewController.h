//
//  StaticViewController.h
//  iOSSample
//
//  Created by Ariel Malka on 8/27/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DIOSDK/DIOAd.h>

NS_ASSUME_NONNULL_BEGIN

@interface StaticViewController : UIViewController

@property (nonatomic, strong) DIOAd *ad;

@end

NS_ASSUME_NONNULL_END
