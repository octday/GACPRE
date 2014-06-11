#pragma once

#include <Core/Shader.h>
#include <Base/Matrix.h>

namespace gcore
{
	class ShaderProgram : public Resource
	{
	public:
		static ShaderProgram* Generate();

		virtual ~ShaderProgram();

		struct Location
		{
		public:
			static Location* Create();
			virtual ~Location() {}

		protected:
			Location() {}
		};

		virtual void SetIsActive(bool isActive) = 0;

		virtual bool SetUniformBool(Location* location, bool b) = 0;
		virtual bool SetUniformInt(Location* location, int i) = 0;
		virtual bool SetUniformFloat(Location* location, float f) = 0;
		virtual bool SetUniformDouble(Location* location, double d) = 0;

		virtual bool SetUniformIntVector2(Location* location, const gbase::IVector2& ivec2) = 0;
		virtual bool SetUniformFloatVector2(Location* location, const gbase::Vector2& vec2) = 0;
		virtual bool SetUniformDoubleVector2(Location* location, const gbase::DVector2&dvec2) = 0;

		virtual bool SetUniformIntVector3(Location* location, const gbase::IVector3& ivec3) = 0;
		virtual bool SetUniformFloatVector3(Location* location, const gbase::Vector3& vec3) = 0;
		virtual bool SetUniformDoubleVector3(Location* location, const gbase::DVector3& dvec3) = 0;

		virtual bool SetUniformIntVector4(Location* location, const gbase::IVector4& ivec4) = 0;
		virtual bool SetUniformFloatVector4(Location* location, const gbase::Vector4& vec4) = 0;
		virtual bool SetUniformDoubleVector4(Location* location, const gbase::DVector4& dvec4) = 0;

		virtual bool SetUniformFloatMatrix3(Location* location, const gbase::Matrix3& mat3) = 0;
		virtual bool SetUniformDoubleMatrix3(Location* location, const gbase::DMatrix3& dmat3) = 0;

		virtual bool SetUniformFloatMatrix4(Location* location, const gbase::Matrix4& mat4) = 0;
		virtual bool SetUniformDoubleMatrix4(Location* location, const gbase::DMatrix4& dmat4) = 0;

		virtual Location* GetAttributeLocation(const std::string& name) = 0;
		virtual Location* GetUniformLocation(const std::string& name) = 0;

		void SetVertexShader(Shader* shader);
		void SetGeometryShader(Shader* shader);
		void SetFragmentShader(Shader* shader);
		void SetTessControlShader(Shader* shader);
		void SetTessEvaluationShader(Shader* shader);
		void SetComputeShader(Shader* shader);

		Shader* GetVertexShader() const;
		Shader* GetGeometryShader() const;
		Shader* GetFragmentShader() const;
		Shader* GetTessControlShader() const;
		Shader* GetTessEvaluationShader() const;
		Shader* GetComputeShader() const;

		virtual bool Load() = 0;

	protected:
		ShaderProgram();
		ShaderPtr mVertexShader;
		ShaderPtr mTessControlShader;
		ShaderPtr mTessEvaluationShader;
		ShaderPtr mGeometryShader;
		ShaderPtr mFragmentShader;
		ShaderPtr mComputeShader;
	};

	typedef std::shared_ptr<ShaderProgram> ShaderProgramPtr;
}