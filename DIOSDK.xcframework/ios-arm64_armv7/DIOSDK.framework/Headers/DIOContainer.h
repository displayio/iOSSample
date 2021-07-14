//
//  DIOContainer.h
//  DIOSDK
//
//  Created by Ariel Malka on 5/21/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOContainerDelegate <NSObject>

- (void)containerDidClose;

@end

@interface DIOContainer : NSObject

@property (nonatomic, strong) id<DIOContainerDelegate> delegate;

- (instancetype)initWithHostView:(UIView*)hostView params:(id)params;
- (void)setContentView:(UIView*)view;
- (int)contentWidth;
- (int)contentHeight;
- (UIView*)closeButtonView;
- (void)useCustomClose:(BOOL)b;
- (void)didTransitionToSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
