//
//  DIOTableAdapter.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/21/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DIOAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOTableAdapter : NSObject

- (instancetype)initWithTableView:(UITableView*)tableView;
- (void)setAd:(DIOAd*)ad forIndexPath:(NSIndexPath*)indexPath;
- (CGFloat)heightForRowAtIndexPath:(NSIndexPath*)indexPath;
- (UITableViewCell*)dequeueReusableCellForIndexPath:(NSIndexPath*)indexPath fullWidth:(BOOL)fullWidth;
- (void)tableViewDidScroll;

@end

NS_ASSUME_NONNULL_END
