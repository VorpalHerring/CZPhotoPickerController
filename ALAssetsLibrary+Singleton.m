//
//  ALAssetsLibrary+Singleton.m
//  Pods
//
//  Created by Samuel Moriyasu on 14/11/14.
//
//

#import "ALAssetsLibrary+Singleton.h"

@implementation ALAssetsLibrary (Singleton)

+ (ALAssetsLibrary*)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
                  {
                      sharedInstance = [[self alloc] init];
                  });
    return sharedInstance;
}

@end
