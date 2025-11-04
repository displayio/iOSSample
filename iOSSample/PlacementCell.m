//
//  PlacementCellTableViewCell.m
//  iOSSample
//
//  Created by Roman Do on 04.11.2025.
//  Copyright © 2025 Display.io. All rights reserved.
//

#import "PlacementCell.h"

static UIColor *MenuColor(void) {
    return UIColor.whiteColor;
}
static UIColor *MenuPressedColor(void) {
    return [UIColor colorWithWhite:0.96 alpha:1.0];
}
static UIColor *MenuStrokeColor(void) {
    return [UIColor colorWithWhite:0.88 alpha:1.0];
}

@interface PlacementCell ()
@property (nonatomic, strong) UIView *cardView;
@property (nonatomic, strong, readwrite) UILabel *idLabel;
@property (nonatomic, strong, readwrite) UILabel *unitTypeLabel;
@end

@implementation PlacementCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier]) {
        self.backgroundColor = UIColor.clearColor;
        self.contentView.backgroundColor = UIColor.clearColor;
        self.selectionStyle = UITableViewCellSelectionStyleNone;

        _cardView = [[UIView alloc] init];
        _cardView.translatesAutoresizingMaskIntoConstraints = NO;
        _cardView.backgroundColor = MenuColor();
        _cardView.layer.cornerRadius = 10.0;
        _cardView.layer.masksToBounds = NO;
        _cardView.layer.shadowColor = [UIColor blackColor].CGColor;
        _cardView.layer.shadowOpacity = 0.22;
        _cardView.layer.shadowRadius = 10.0;
        _cardView.layer.shadowOffset = CGSizeMake(0, 4); 
        
        [self.contentView addSubview:_cardView];
        _cardView.layoutMargins = UIEdgeInsetsMake(12, 12, 12, 12);
        _idLabel = [[UILabel alloc] init];
        _idLabel.translatesAutoresizingMaskIntoConstraints = NO;
        _idLabel.font = [UIFont systemFontOfSize:16];
        _idLabel.numberOfLines = 1;

        _unitTypeLabel = [[UILabel alloc] init];
        _unitTypeLabel.translatesAutoresizingMaskIntoConstraints = NO;
        _unitTypeLabel.font = [UIFont systemFontOfSize:16];
        _unitTypeLabel.textAlignment = NSTextAlignmentRight;
        _unitTypeLabel.numberOfLines = 1;

        [_cardView addSubview:_idLabel];
        [_cardView addSubview:_unitTypeLabel];

        UILayoutGuide *m = _cardView.layoutMarginsGuide;

        [NSLayoutConstraint activateConstraints:@[
            [_cardView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor constant:6],
            [_cardView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor constant:-6],
            [_cardView.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor constant:10],
            [_cardView.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor constant:-10],

            [_idLabel.leadingAnchor constraintEqualToAnchor:m.leadingAnchor],
            [_idLabel.topAnchor constraintEqualToAnchor:m.topAnchor],
            [_idLabel.bottomAnchor constraintEqualToAnchor:m.bottomAnchor],

            [_unitTypeLabel.trailingAnchor constraintEqualToAnchor:m.trailingAnchor],
            [_unitTypeLabel.centerYAnchor constraintEqualToAnchor:_idLabel.centerYAnchor],
            [_unitTypeLabel.leadingAnchor constraintGreaterThanOrEqualToAnchor:_idLabel.trailingAnchor constant:8]
        ]];
    }
    return self;
}

- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated {
    [super setHighlighted:highlighted animated:animated];
    [self animatePressed:highlighted || self.isSelected animated:animated];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    [self animatePressed:selected || self.isHighlighted animated:animated];
}

- (void)animatePressed:(BOOL)pressed animated:(BOOL)animated {
    UIColor *target = pressed ? MenuPressedColor() : MenuColor();
    if (animated) {
        [UIView animateWithDuration:0.15 animations:^{
            self.cardView.backgroundColor = target;
        }];
    } else {
        self.cardView.backgroundColor = target;
    }
}

@end

