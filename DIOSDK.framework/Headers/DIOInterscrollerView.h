//
//  DIOInterscrollerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOInterscrollerViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)exposureDidChange:(int)exposure y:(int)y height:(int)height;
- (void)didActivate;
- (void)didDeactivate;

@end

@interface DIOInterscrollerView : UIView

@property (nonatomic, weak) id<DIOInterscrollerViewDelegate> delegate;

- (instancetype)initWithParams:(id)params;

- (void)setContainedView:(UIView*)view;
- (void)cancel;
- (void)skip;

@end

NS_ASSUME_NONNULL_END
