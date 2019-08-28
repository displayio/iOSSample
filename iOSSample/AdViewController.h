//
//  AdViewController.h
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PlacementType.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdViewController : UIViewController

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic) PlacementType placementType;

@end

NS_ASSUME_NONNULL_END
