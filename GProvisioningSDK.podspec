Pod::Spec.new do |s|

  s.name         = "GProvisioningSDK"
  s.version = "1.0.2"
  s.summary      = "This is the Provisioning SDK for iOS devices."
  s.homepage     = "https://github.com/YinJone/WPASDK_gotell"
	s.license      = "MIT"
	s.author       = { "Jone.yin" => "yin_jone@163.com" }
  s.ios.deployment_target = '9.0'
  s.vendored_framework = 'ProvisioningSDK.framework'
  s.frameworks = "Foundation"
  s.requires_arc = true
  s.source = { git: 'https://github.com/YinJone/ProvisioningSDK_gotell.git', :tag => s.version}
  #s.dependency 'KeychainSwift', '10.0.0'
  s.dependency 'CocoaLumberjack', '3.3.0'
end