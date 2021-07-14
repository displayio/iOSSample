//
//  DIOScreenCapture.h
//  DIOSDK
//
//  Created by rdorofeev on 21.10.2020.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOScreenCapture : NSObject

@property (nonatomic) UIImage* image;
@property (nonatomic) NSInteger containerWidth;
@property (nonatomic) NSInteger containerHeight;
@property (nonatomic) NSInteger adWidth;
@property (nonatomic) NSInteger adHeight;
@property (nonatomic) NSInteger pageWidth;
@property (nonatomic) NSInteger pageHeight;
@property (nonatomic) CGRect visibleRect;

- (instancetype)initWithProperties:(UIImage*) image
                containerWidth: (NSInteger) containerWidth
                containerHeight: (NSInteger) containerHeight
                adWidth: (NSInteger) adWidth
                adHeight: (NSInteger) adHeight
                pageWidth: (NSInteger) pageWidth
                pageHeight: (NSInteger) pageHeight
                visibleRect: (CGRect) visibleRect;
@end

NS_ASSUME_NONNULL_END
