//
//  ViewController.m
//  DebugFromWeb
//
//  Created by Kiran on 31/03/15.
//  Copyright (c) 2015 Kiran. All rights reserved.
//

#import "ViewController.h"
#import "Nighthawk.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    NSLog(@"from view 1");
       [[Nighthawk sharedInstance] logMessage:@"test"
                                   message:@"from view 1"];
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
