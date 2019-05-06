//
//  CustomCell2.m
//  iOSSample
//
//  Created by Ariel Malka on 4/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "CustomCell2.h"

@implementation CustomCell2

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.contentView.backgroundColor = [UIColor orangeColor];
    }
    
    return self;
}

@end
