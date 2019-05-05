//
//  PlacementViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "PlacementViewController.h"
#import "ViewController.h"

@interface PlacementViewController ()

@end

@implementation PlacementViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.data count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    switch ([self.data[indexPath.row][@"type"] intValue]) {
        case PlacementTypeInterstitial:
            cell.textLabel.text = @"Interstitial";
            break;
            
        case PlacementTypeBanner:
            cell.textLabel.text = @"Banner";
            break;
    }
    
    return cell;
}

@end
