//
//  AdViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "AdViewController.h"

@interface AdViewController ()

@property (weak, nonatomic) IBOutlet UIButton *loadButton;
@property (weak, nonatomic) IBOutlet UIButton *showButton;

@end

@implementation AdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)loadPressed:(id)sender {
    NSLog(@"LOAD");
}

- (IBAction)showPressed:(id)sender {
    NSLog(@"SHOW");
}

@end
