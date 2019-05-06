//
//  CustomCell1.m
//  iOSSample
//
//  Created by Ariel Malka on 4/11/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "CustomCell1.h"

@implementation CustomCell1

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.contentView.backgroundColor = [UIColor redColor];
    }
    
    return self;
}

@end
