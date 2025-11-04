//
//  PlacementViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "PlacementViewController.h"
#import "PlacementType.h"
#import "PlacementCell.h"
#import "AdViewController.h"
#import "FeedViewController.h"
#import "InterscrollerViewController.h"
#import "ISCollectionViewController.h"
#import "iOSSampleBrandio-Swift.h"

@implementation PlacementViewController
BOOL didLayoutSubviews;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.tableView registerClass:PlacementCell.class forCellReuseIdentifier:@"PlacementCell"];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    
    UILabel *title = [[UILabel alloc] init];
    title.text = @"Display.io";
    title.textColor = [UIColor colorWithWhite:0 alpha:1];
    title.font = [UIFont boldSystemFontOfSize:16];
    
    UILabel *subTitle = [[UILabel alloc] init];
    subTitle.text = @" | Demo Application";
    subTitle.textColor = UIColor.grayColor;
    subTitle.font = [UIFont systemFontOfSize:16];
    
    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[title, subTitle]];
    stack.axis = UILayoutConstraintAxisHorizontal;
    stack.alignment = UIStackViewAlignmentCenter;
    stack.spacing = 0;
    
    UIView *container = [[UIView alloc] initWithFrame:CGRectZero];
    container.translatesAutoresizingMaskIntoConstraints = NO;
    [container addSubview:stack];
    
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    [NSLayoutConstraint activateConstraints:@[
        [stack.centerYAnchor constraintEqualToAnchor:container.centerYAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:container.trailingAnchor]
    ]];
    
    self.navigationItem.titleView = container;
    
    UINavigationBarAppearance *appearance = [[UINavigationBarAppearance alloc] init];
    [appearance configureWithOpaqueBackground];
    appearance.backgroundColor = [UIColor colorWithWhite:0xf8/255.0 alpha:1.0];
    
    self.navigationController.navigationBar.standardAppearance = appearance;
    self.navigationController.navigationBar.scrollEdgeAppearance = appearance;
}



- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.data count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    PlacementCell *cell = [tableView dequeueReusableCellWithIdentifier:@"PlacementCell" forIndexPath:indexPath];
    
    NSString *placementId = self.data[indexPath.row][@"id"];
    PlacementType placementType = [self.data[indexPath.row][@"type"] integerValue];
    
    cell.idLabel.text = placementId;
    cell.idLabel.textColor = UIColor.blackColor;
    
    NSString *typeString;
    switch (placementType) {
        case PlacementTypeInterstitial:
            typeString = @"Interstitial";
            break;
        case PlacementTypeInFeed:
            typeString = @"Infeed";
            break;
        case PlacementTypeInterscrollerVideo:
            typeString = @"Interscroller Video";
            break;
        case PlacementTypeInterscrollerVideoORTB:
            typeString = @"Interscroller Video CollectionView + oRTB";
            break;
        case PlacementTypeInterscrollerHtml:
            typeString = @"Interscroller Display";
            break;
        case PlacementTypeBanner:
            typeString = @"Banner";
            break;
        case PlacementTypeMediumRectangle:
            typeString = @"Medium Rectangle";
            break;
        case PlacementTypeInFeedSwiftUI:
            typeString = @"Infeed (SwiftUI)";
            break;
        case PlacementTypeInterscrollerSwiftUI:
            typeString = @"Interscroller (SwiftUI)";
            break;
        default:
            typeString = @"Unknown";
            break;
    }
    
    cell.unitTypeLabel.text = typeString;
    cell.unitTypeLabel.textColor = UIColor.grayColor;
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    NSString *placementId = self.data[indexPath.row][@"id"];
    PlacementType placementType = [self.data[indexPath.row][@"type"] integerValue];
    
    if (placementType == PlacementTypeInFeed) {
        FeedViewController *viewController = [FeedViewController new];
        viewController.placementId = placementId;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:YES completion:nil];
    } else if (placementType == PlacementTypeInterscrollerVideo
        || placementType == PlacementTypeInterscrollerHtml) {
        InterscrollerViewController *viewController = [InterscrollerViewController new];
        viewController.placementId = placementId;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:YES completion:nil];
    } else if (placementType == PlacementTypeInterscrollerVideoORTB) { 
        ISCollectionViewController *viewController = [ISCollectionViewController new];
        viewController.placementId = placementId;
        viewController.isORTB = YES;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:YES completion:nil];
    }
    else if (placementType == PlacementTypeInFeedSwiftUI || placementType == PlacementTypeInterscrollerSwiftUI) {
        UIViewController *feedViewController = [SwiftUIViewProvider
                                                createFeedViewControllerWithPlacementId:placementId
                                                adUnitType:placementType == PlacementTypeInFeedSwiftUI ? @"infeed" : @"interscroller"];
        [self.navigationController pushViewController:feedViewController animated:YES];
    } else {
        AdViewController *adViewController = (AdViewController*)[[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"AdViewController"];
        adViewController.placementId = placementId;
        adViewController.placementType = placementType;
        
        [self.navigationController pushViewController:adViewController animated:YES];
    }
}

@end
