//
//  PlacementCellTableViewCell.h
//  iOSSample
//
//  Created by Roman Do on 04.11.2025.
//  Copyright © 2025 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PlacementCell : UITableViewCell

@property (nonatomic, strong, readonly) UILabel *idLabel;
@property (nonatomic, strong, readonly) UILabel *unitTypeLabel;

@end

NS_ASSUME_NONNULL_END
