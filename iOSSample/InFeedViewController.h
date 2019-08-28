//
//  InFeedViewController.h
//  iOSSample
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DIOSDK/DIOAd.h>

NS_ASSUME_NONNULL_BEGIN

@interface InFeedViewController : UITableViewController

@property (nonatomic, strong) DIOAd *ad;

@end

NS_ASSUME_NONNULL_END
