//
//  InterscrollerViewController.h
//  iOSSample
//
//  Created by Ariel Malka on 1/12/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface InterscrollerViewController : UITableViewController

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic) BOOL isORTB;

@end

NS_ASSUME_NONNULL_END
